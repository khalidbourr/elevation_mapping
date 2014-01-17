/*
 * TransformationMath.hpp
 *
 *  Created on: Dec 2, 2013
 *      Author: Péter Fankhauser
 *	 Institute: ETH Zurich, Autonomous Systems Lab
 */

#pragma once

// Eigen
#include <Eigen/Core>

namespace starleth_elevation_msg {

Eigen::Matrix2i getBufferOrderToMapFrameAlignment();

/*!
 * Gets the position of a cell specified by its index in the map frame.
 * @param[out] position the position of the center of the cell in the map frame.
 * @param[in] index of the cell.
 * @param[in] mapLength the lengths in x and y direction.
 * @param[in] resolution the resolution of the map.
 * @return true if successful.
 */
bool getPositionFromIndex(Eigen::Vector2d& position,
                          const Eigen::Array2i& index,
                          const Eigen::Array2d& mapLength,
                          const double& resolution,
                          const Eigen::Array2i& bufferSize = Eigen::Array2i::Zero(),
                          const Eigen::Array2i& bufferStartIndex = Eigen::Array2i::Zero());

/*!
 * Gets the index of the cell which contains a position in the map frame.
 * @param[out] index of the cell.
 * @param[in] position the position in the map frame.
 * @param[in] mapLength the lengths in x and y direction.
 * @param[in] resolution the resolution of the map.
 * @return true if successful, false if position outside of map.
 */
bool getIndexFromPosition(Eigen::Array2i& index,
                          const Eigen::Vector2d& position,
                          const Eigen::Array2d& mapLength,
                          const double& resolution,
                          const Eigen::Array2i& bufferSize = Eigen::Array2i::Zero(),
                          const Eigen::Array2i& bufferStartIndex = Eigen::Array2i::Zero());

bool checkIfPositionWithinMap(const Eigen::Vector2d& position,
                              const Eigen::Array2d& mapLength);

/*!
 * Align position with grid.
 * @param[in] position.
 * @param[out] alignedPosition.
 * @return true if successful.
 */
bool getAlignedPosition(const Eigen::Vector2d& position,
                        Eigen::Vector2d& alignedPosition,
                        const Eigen::Array2d& mapLength,
                        const double& resolution);

bool getIndexShiftFromPositionShift(Eigen::Array2i& indexShift,
                                    const Eigen::Vector2d& positionShift,
                                    const double& resolution);

void mapIndexWithinRange(Eigen::Array2i& index,
                         const Eigen::Array2i& bufferSize);

void mapIndexWithinRange(int& index, const int& bufferSize);

} // namespace